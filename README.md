# Tiny C Projects

## Context

I'm reading Tiny C Projects, written by Dan Gookin.

## What I'd like to achieve

I want to add to this repository each tiny project with explanations.

"The best way to learn programming is to use small demonstration programs. Each one focusing on a specific part of the language."

## Compiler of choice

I'm using gcc to compile c code to executable programs.
`gcc -Wall main.c -o main`

The -Wall flag enables all compiler's warning messages.
The -o option enables us to choose our executable's name (in our example, it will generate a main.exe file)

## Notes

HTML5 URL encoding rules:
- Alphanumeric characters are not translated (0 to 9, A to Z, upper and lowercase)
- The characters - (dash), . (period), _ (underscore), and * (asterisk) are retained.
- Spaces are converted into the + (plus) character, though the %20 code is also used.
- All the other characters are represented as their hexadecimal ASCII value, prefixed with a percent sign.
- If the data to encode is wider than a byte, such as a Unicode character, it's divided into byte-size values, each a 2-digit hex number prefixed with a percent sign. This final point mai not be consistent for all wide-character values.

Creating a library:
- You'll need a source code file (.c) and a header file (.h)
- The following command with the -c switch turns source code into object code (.o)
`gcc -Wall -c mylibrary.c`
- The next step is to use the archive utility 'ar' to build the library. This command is followed by 3 arguments: command switches, the name of the library file, and finally the object code files required to build the library. For example:
`ar -rcs libmylibrary.a mylibrary.o`
r = Inserts file(s) into the archive
c = Creates the archive
s = Indexes the archive
- Upon success, the 'ar' utility creates the library named "libmylibrary.a". This naming format follows the conventions used in Linux: libname.a

Using a library:
- To use a library other than the standard C library, its name must be specified at build time.
- For a library you create in the same folder as your program, specify the -L switch to direct the linker to look in the current directory. For example:
`gcc -Wall -L. libsample.c -lmystring`