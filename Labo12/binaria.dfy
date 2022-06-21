predicate ordenado(a: array<int>)
requires a != null;
reads a;
{
	forall i,j :: (0 <= i < j < a.Length ==> a[i] <= a[j])
}

method BusquedaBinaria(a: array<int>, x: int) returns (ret: bool)

	requires a != null && a.Length > 1
	requires ordenado(a) && a[0] <= x < a[a.Length-1]
	ensures ret == exists i :: (0 <= i < a.Length && a[i] == x)

{
	var i := 0;
	var j := a.Length - 1;

	while( i+1 < j )
	invariant 0 <= i < j < a.Length && a[i] <= x < a[j]
	decreases j-i
	{
		var k := (i+j) / 2;
		if (a[k] <= x)
		{
			i := k;
		}
		else
		{
			j := k;
		}
	}

	return a[i] == x;
}
