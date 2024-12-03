echo "Outputting contents of input.txt..."
cat input.txt

echo "Running './sed input.txt Linux Windows'..."
./sed input.txt Linux Windows

echo "Running 'sed' replacement for 'Linux' -> 'Windows'..."
< input.txt sed 's/Linux/Windows/g' > sed.output.txt

echo "Diffing outputs..."
diff -s sed.output.txt input.txt.replace

echo "Running './sed input.txt the 7H3'..."
./sed input.txt the 7H3

echo "Running 'sed' replacement for 'the' -> '7H3'..."
< input.txt sed 's/the/7H3/g' > sed.output.txt

echo "Diffing outputs..."
diff -s sed.output.txt input.txt.replace

rm sed.output.txt input.txt.replace

echo "Running './sed input.txt ' ' _'..."
./sed input.txt " " _

echo "Running 'sed' replacement for spaces with underscores..."
< input.txt sed 's/ /_/g' > sed.output.txt

echo "Diffing outputs..."
diff -s sed.output.txt input.txt.replace

rm sed.output.txt input.txt.replace

echo "Running 1337 replacement with './sed'..."
./sed loremipsum.txt a 4 && \
./sed loremipsum.txt.replace e 3 && \
./sed loremipsum.txt.replace.replace t 7 && \
./sed loremipsum.txt.replace.replace.replace l 1 && \
./sed loremipsum.txt.replace.replace.replace.replace o 0 && \
./sed loremipsum.txt.replace.replace.replace.replace.replace s 5

echo "Running 1337 replacement with 'sed'..."
< loremipsum.txt sed 's/a/4/g' | \
sed 's/e/3/g' | \
sed 's/t/7/g' | \
sed 's/l/1/g' | \
sed 's/o/0/g' | \
sed 's/"s"/5/g' > sed.output.txt

echo "Diffing outputs..."
diff -s sed.output.txt loremipsum.txt.replace.replace.replace.replace.replace

rm loremipsum.txt.* sed.output.txt