method Add(x: int, y: int) returns (r: int)
ensures r == x+y
{
	var a := x+1;
	var b := a-2;
	r := b+y+1;
}