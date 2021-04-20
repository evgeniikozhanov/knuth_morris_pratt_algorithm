# Knuth-Morris-Pratt algorithm

It's just a small module in C for Python.

The module implements Knuth-Morris-Pratt algorithm for string matching.

The example of using:

```
>> import knuth_morris_pratt_algorithm
>> knuth_morris_pratt_algorithm.match_string('abc', 'abcabc')

(0, 3)
```

where `abc` is a pattern, `abcabc` is a text, and result is a tuple of positions where the pattern matched the text. 
