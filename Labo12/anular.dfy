
method Anular(a: array<int>)

requires a != null
modifies a

ensures forall j :: (0 <= j < a.Length && old(a)[j] <= 0 ==> a[j] == 0)
ensures forall j :: (0 <= j < a.Length && old(a)[j] >= 0 ==> a[j] == old(a)[j])

{
	var i := 0;

	while( i < a.Length )

		invariant 0 <= i <= a.Length
		invariant forall j :: (0 <= j < i && old(a)[j] <= 0 ==> a[j] == 0)
		invariant forall j :: (0 <= j < i && old(a)[j] >= 0 ==> a[j] == old(a)[j])
		decreases a.Length - i;

	{
		if( a[i] < 0 )
		{
			a[i] := 0;
		}

		i := i+1;
	}
}
