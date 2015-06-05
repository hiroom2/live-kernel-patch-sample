all:
	$(MAKE) -C patched
	$(MAKE) -C patch

clean:
	$(MAKE) -C patched clean
	$(MAKE) -C patch clean
