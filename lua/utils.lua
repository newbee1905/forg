Forg = {}
Len = 0

function _(path)
	Len = Len + 1
	return function(patterns)
		Forg[path] = patterns
	end
end

--[[
    Forg = {}                                                                  \
    Len = 0                                                                    \
                                                                               \
    function _(path)                                                           \
			Len = Len + 1                                                            \
			return function(patterns)                                                \
				Forg[path] = patterns                                                  \
			end                                                                      \
    end                                                                        \
]]
