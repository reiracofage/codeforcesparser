Codeforcesparser
================

Codeforcesparser is a set of programs that parse a contest from codeforces. They
download the problem specifications and parse them, creating an unique file for
each sample input and output. It also comes with a test script that compiles,
runs and tests your solution with the sample files.

Install
-------

First, create the directory on which you want to work (say, ~/codeforces/).

    mkdir ~/codeforces

Insert the *parser* directory in it (not its files) and enter it.

    cp -r location/to/parser ~/codefoces/
    cd ~/codeforces/parser/

Compile *gerainout.cpp*.

    make gerainout

You are done!

Usage
-----

From the directory you want to work (say, ~/codeforces/), run

    ./parser/limpa.sh

to clear your workspace (if not clean already). Then, run

    ./parser/parser.sh <CONTESTID>

where <CONTESTID> is the *internal* contest id. This id can be seen in the
URL relative to the contest.

A directory will be created for each problem containing all relevant files.
If you want to solve a problem (say, problem A), do

    cd A
    vim A.cpp # or your favorite editor
    (solve the problem!)
    ./testa.sh

The last line will compile your solution, run it for all sample inputs and
*diff* them with the sample outputs.
