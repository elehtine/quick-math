LATEXCMD = pdflatex -shell-escape -output-directory build

.PHONY: all
all: | build
	$(LATEXCMD) main.tex
	cp build/main.pdf main.pdf

build:
	mkdir -p build

clean:
	$(RM) build/*
