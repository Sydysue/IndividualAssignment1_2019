using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Runtime.InteropServices;

public class SaveLoadWrapper
{
    [DllImport("Assignment_1.dll")]
    public static extern bool saveToFile(string filename, float x, float y, float z);

    [DllImport("Assignment_1.dll")]
    public static extern bool loadTheFile(string filename, ref float x, ref float y, ref float z);
}