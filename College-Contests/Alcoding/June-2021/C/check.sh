for ((i=1;;i++)) do
	echo $i
	./gen $i > in
	diff -w <(./C < in) <(./C_brute < in) || break
done
