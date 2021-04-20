import unittest

import knuth_morris_pratt_algorithm


class TestMatchString(unittest.TestCase):

    def test_match_string(self):
        self.assertEqual(knuth_morris_pratt_algorithm.match_string('abc', 'abcabc'), (0, 3))
        self.assertEqual(knuth_morris_pratt_algorithm.match_string('ababaca', 'bacbababaabcbab'), ())


if __name__ == '__main__':
    unittest.main()
