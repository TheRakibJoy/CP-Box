const int B = 31;
int basis[B], sz;
void add(int mask)
{
	for (int i = B - 1; i >= 0; i--)
	{
		if ((mask & 1 << i) == 0)
			continue;
		if (!basis[i])
		{
			basis[i] = mask;
			++sz;
			return;
		}
		mask ^= basis[i];
	}
}
