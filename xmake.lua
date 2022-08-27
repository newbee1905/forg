add_rules("mode.debug", "mode.release")

target("forg")
	set_kind("binary")
	add_files("src/*.c")
	add_includedirs("/usr/include/luajit-2.1/", "/usr/include", "/usr/local/include", "lib")
	add_linkdirs("/usr/local/lib", "/usr/lib", "/usr/lib/x86_64-linux-gnu")
	add_links("luajit")
	set_languages("c2x")
	set_optimize("fastest")
	add_syslinks("z", "pthread")
-- add_cxflags("-stdnolib", "-fno-strict-aliasing")
	-- add_ldflags("-llua", "-ldl", "-lpthread", { force = true })