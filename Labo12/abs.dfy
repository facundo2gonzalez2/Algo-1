method Abs(x: int) returns (r: int)
ensures (x < 0 && r == -x) || (x >= 0 && r == x)
{
	if( x > 0 )
	{
		r := x;
	}
	else
	{
		r := -x;
	}
}