# Knuth-Morris-Pratt algorithm

It's just my first module in C for Python.

The module implement Knuth-Morris-Pratt algorithm for string matching.

Example of using:

```
>> import knuth_morris_pratt_algorithm
>> knuth_morris_pratt_algorithm.match_string('abc', 'abcabc')

(0, 3)
```

where `abc` is a pattern, `abcabc` is a text, and result is a tuple of positions where the pattern matched the text. 
