while True:
	ret = "Missing"
	s = input()
	if s == "EOI":
		break
	if s.lower().find("nemo") >= 0 :
		ret = "Found"
	print (ret)