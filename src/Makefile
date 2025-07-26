all: s21_cat s21_grep

s21_cat:
	$(MAKE) -C cat

s21_grep:
	$(MAKE) -C grep
	
clang:
	$(MAKE) -C cat style
	$(MAKE) -C grep style
	
clean:
	$(MAKE) -C cat clean
	$(MAKE) -C grep clean

check:
	$(MAKE) -C cat check
	$(MAKE) -C grep check
test:
	$(MAKE) -C cat test
	$(MAKE) -C grep test