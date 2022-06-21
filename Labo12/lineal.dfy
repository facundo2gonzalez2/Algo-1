
method Buscar(a: array<int>, x: int) returns (ret: bool)

	requires a != null
	ensures ret == exists i :: (0 <= i < a.Length && a[i] == x)

{
	var i := 0;

	while( i < a.Length && a[i] != x )
	invariant 0 <= i <= a.Length && forall j :: (0 <= j < i ==> a[j] != x)
	{
		i := i+1;
	}

	return i < a.Length;
}
