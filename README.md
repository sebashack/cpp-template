# C++ Project Template

## First time setup

```
./first-time-install.sh
```

## Build

```
make build
```

## Restyle code

```
make restyle
```

## Clean

```
make clean
```

## Execute word generator

The executable binary will be generated in the `dist` directory on the root of this project:

Execute:

```
./dist/main WORDS_FILEPATH
```

where `WORDS_FILEPATH` is the path to the file with the list of words.

There are three sample files with words in this projects, namely, `dictionary1.txt`, `dictionary2.txt` and `dictionary3.txt`:

- `dictionary1.txt` is the file with the most balanced distribution of subject, verbs and predicates. It'll generate
   more sacrambled output.
- `dictionary2.txt` is an extreme case where there are too few subjects compared to the number of verbs and predicates.
   verbs and predicates are similar in size.
- `dictionary3.txt` is an extreme case where there is just 1 subject, 2 predicates, and the rest are verbs. This is the
   most monotone sample, but nevertheless it won't generate duplicates.


If you want to create your own dictionaries, you must follow the same format in those files:

```
p:rapidamente
p:tenuemente
...
s:la sirena
s:el oso
...
v:baila
v:vive
```

In general we have that each line must be of the form `type:word`. Only the first 30 lines will be read and there must
be at least 1 instance of each type and no more than 27 instances of a specific type--otherwise it'll be impossible not
to generate duplicates.
