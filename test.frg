#!frog

function test
    a = 2
    print("-TEST")
    print(a)
    print(b)
    print("-END")
end

function main
    a = 1
    b = 2
    print(a & "and" & b)
    test()
    print(a & "and" & b)
end
