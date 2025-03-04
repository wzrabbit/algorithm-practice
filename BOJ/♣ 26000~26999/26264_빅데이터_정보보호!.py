input()
S = input()
security_count = S.count("security")
bigdata_count = S.count("bigdata")

if security_count > bigdata_count:
    print("security!")
elif security_count < bigdata_count:
    print("bigdata?")
else:
    print("bigdata? security!")
