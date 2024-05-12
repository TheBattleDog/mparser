# Manhwa Name Parser

All it does is simply remove the '-' characters in a string it doesn't have to be Manhwa name genius!!

Update:

• It got smarter it also removes any annoying special characters at beginning and end of a string!!
• Also it capitalises the string!!

It also copies the output to windows Clipboard, yep it only works for windows(Maybe for Linux?)!!

Add it as global variable and use it as a command in CMD or PowerShell!!

It is uses ClipboardXX to copy to clipboard.

## Installation
Build it however you want, I guess. Just use "g++ mparser.cpp -o mparse"

## Usage
Command: 
```
> mparse <name of manhwa>
```

Example:
```
> mparse %^the-main-characters-that-only-i-know??!
(The Main Characters That Only I Know) - [Copied to Clipboard]
```

