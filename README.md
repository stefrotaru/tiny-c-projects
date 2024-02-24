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