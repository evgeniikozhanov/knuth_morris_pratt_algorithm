import unittest

import knuth_morris_pratt_algorithm


def compute_prefix_function(s):
    m = len(s)
    pi: list = [0, ]
    for i in range(1, m):
        k = pi[i - 1]
        while (k > 0) and (s[i] != s[k]):
            k = pi[k - 1]
        if s[i] == s[k]:
            k += 1
        pi.append(k)
    return pi


class TestMatchString(unittest.TestCase):

    def test_match_string(self):
        self.assertEqual(knuth_morris_pratt_algorithm.match_string('abc', 'abcabc'), (0, 3))
        self.assertEqual(knuth_morris_pratt_algorithm.match_string('ababaca', 'bacbababaabcbab'), ())
        self.assertEqual(knuth_morris_pratt_algorithm.match_string('abacab', 'abacaabacc'), ())
        self.assertEqual(knuth_morris_pratt_algorithm.match_string('xxzzzzzzzzx', 'xxxzzzzzzzzzxyxzzzzzzzzzzzxyzzzz'),
                         ())

    def test_compute_prefix(self):
        self.assertEqual(compute_prefix_function('xxzzzzzzzzx'), [0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1])

    def test_match_string_algorithm(self):
        def match_string(sample_str, text_str):
            result = []
            n = len(text_str)
            m = len(sample_str)
            pi = compute_prefix_function(sample_str)
            q = 0
            for i in range(n):
                while (q > 0) and (sample_str[q] != text_str[i]):
                    q = pi[q - 1]
                if sample_str[q] == text_str[i]:
                    q += 1
                if q == m:
                    result.append(i - m + 1)
                    q = pi[q - 1]
            return result

        self.assertEqual(match_string('xxzzzzzzzzx', 'xxxzzzzzzzzzxyxzzzzzzzzzzzxyzzzz'), [])


if __name__ == '__main__':
    unittest.main()
