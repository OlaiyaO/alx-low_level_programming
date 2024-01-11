#!/bin/bash

largest_palindrome=0

for i in {900..999}; do
	for j in {900..999}; do
		product=$((i * j))
		if [ $product -eq $(echo "$product" | rev) ] && [ $product -gt $largest_palindrome ]; then
			largest_palindrome=$product
		fi
	done
done

echo -n $largest_palindrome > 102-result
