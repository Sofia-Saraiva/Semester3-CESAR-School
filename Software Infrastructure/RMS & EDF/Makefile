CFLAGS = -Wall -Werror

.PHONY: clean

rate: real.c
	@gcc $(CFLAGS) -o rate real.c -DRATE

edf: real.c
	@gcc $(CFLAGS) -o edf real.c -DEDF

clean:
	@rm -f rate edf
	@rm -f real edf