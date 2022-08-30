add_rules("mode.debug", "mode.release")
-- add_rules("mode.debug")


target("forg")
	set_kind("binary")
	add_files("src/*.c")
	add_includedirs("/usr/include", "/usr/local/include", "include")
	add_linkdirs("/usr/local/lib", "/usr/lib", "/usr/lib/lua/5.4")
	add_links("lua", "m", "dl")
	set_languages("c2x")
	set_optimize("fastest")
	add_syslinks("z", "pthread")
	-- add_ldflags("-llua", "-ldl", "-lpthread", { force = true })
