LATEXCMD = pdflatex -shell-escape -output-directory build


quick-math.pdf: | build
	$(LATEXCMD) quick-math.tex
	cp build/quick-math.pdf quick-math.pdf

build:
	mkdir -p build

clean:
	$(RM) build/*
