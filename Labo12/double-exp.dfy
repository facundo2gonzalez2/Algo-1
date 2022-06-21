function Exp(a: int, n: int): int
requires n >= 0;
{
	if n == 0 then 1 else a * Exp(a, n-1)
}

lemma paso(j: int)
requires j >= 0
ensures Exp(2,j+3) == 8 * Exp(2,j)
{
}

method Potencia(n: int) returns (res: int)
requires 0 <= n;
ensures res == Exp(2, 3*n);
{
	var i := 0;
	res := 1;
	while( i < n )
	invariant 0 <= i <= n && res == Exp(2, 3*i);
	decreases n-i;
	{
		paso(3*i);

		res := 8 * res;
		i := i+1;
	}

	return res;
}
