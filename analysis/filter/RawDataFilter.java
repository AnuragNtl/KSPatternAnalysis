package filter;
import java.io.*;
import java.util.*;
public abstract class RawDataFilter
{
	protected byte data[];
	public RawDataFilter(byte data[])
	{
		this.data=data;
	}
	public abstract byte[] filter(byte data[]);
	public abstract void transfter(OutputStream out);
};
