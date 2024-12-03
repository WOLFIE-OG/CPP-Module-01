# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    actions_runner.py                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otodd <otodd@student.42london.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 11:56:46 by otodd             #+#    #+#              #
#    Updated: 2024/12/03 15:30:44 by otodd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import os
import logging
from yaml import safe_load
from subprocess import Popen, PIPE
from uuid import uuid4
from pathlib import Path
from git import Repo
from git.util import RemoteProgress

JOB_NAME = "build"
COLORS = {
    "DEBUG": "\033[94m",
    "INFO": "\033[92m",
    "WARNING": "\033[93m",
    "ERROR": "\033[91m",
    "CRITICAL": "\033[95m",
    "RESET": "\033[0m"
}

class ColoredFormatter(logging.Formatter):
    def format(self, record):
        color = COLORS.get(record.levelname, COLORS["RESET"])
        record.levelname = f"{color}{record.levelname}{COLORS['RESET']}"
        return super().format(record)

console_handler = logging.StreamHandler()
console_handler.setLevel(logging.DEBUG)
log_format = "[%(levelname)s] :: [%(asctime)s] :: %(message)s"
formatter = ColoredFormatter(log_format, datefmt='%Y-%m-%d %H:%M:%S')
console_handler.setFormatter(formatter)
ID = uuid4().__str__()
logger = logging.getLogger("actions_runner")
logging.basicConfig(level=logging.INFO, filename=Path(ID + ".log"))
logger.addHandler(console_handler)

TMP_DIR = Path("/tmp/actions_runner")
if not os.path.exists(TMP_DIR):
    os.mkdir(TMP_DIR)

with open(".github/workflows/makefile.yml") as f:
    action = safe_load(f)

logger.info("Fetching repo url")
proc = Popen("git config --get remote.origin.url", stdout=PIPE, shell=True)
repo_url = proc.stdout.read().decode("utf-8").strip()
repo_dir = Path(TMP_DIR, os.getcwd().split("/")[0], ID)
os.mkdir(repo_dir)
logger.info(f"Cloning [{repo_url}] into {repo_dir}")

class Progress(RemoteProgress):
    def __init__(self) -> None:
        super().__init__()
    def update(self, *args):
        logger.info(self._cur_line)

Repo.clone_from(multi_options=["--recursive", "--progress"], to_path=repo_dir, url=repo_url, progress=Progress())

logger.info(f"Running steps for {action.get("name")} on job {JOB_NAME}")

for step in action["jobs"][JOB_NAME].get("steps"):
    if not step.get("run"):
        continue
    logger.info(f"Running step: {step.get("name")}")
    proc = Popen(step.get("run"), cwd=Path(repo_dir.__str__() + "/" + step.get("working-directory")) if step.get("working-directory") else Path(repo_dir), shell=True)
    ret = proc.wait(500)
    if ret != 0 and step.get("continue-on-error") is not True:
        logger.error("Step failed!")
        break
    print(5 * '\n')