from distutils.core import setup, Extension


def main():
    setup(
        name="knuth_morris_pratt_algorithm",
        version="0.0.1",
        description="Python interface for the Knuth-Morris-Pratt algorithm C library function",
        author="Evgenii Kozhanov",
        author_email="evgenii.kozhanov@gmail.com",
        ext_modules=[Extension("knuth_morris_pratt_algorithm", ["match_string_module.c"])],
    )


if __name__ == "__main__":
    main()
