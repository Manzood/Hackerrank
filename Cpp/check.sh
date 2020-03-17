for ((i=1;;i++)) do
	#echo $i
	#./gen $i > in
	diff -w <(./a.out < in) expected || break
done