using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SaveLoad : MonoBehaviour
{
    public GameObject boi; //player
    private string file = "player_pos.txt";
  public void save()
    {
        print("SAVE");
        if (!SaveLoadWrapper.saveToFile(file, boi.transform.position.x, boi.transform.position.y, boi.transform.position.z))
        {
            print("OOPS");
        }
    }

   public void load()
    {
        print("LOAD");
        Vector3 temp = new Vector3();
        if (!SaveLoadWrapper.loadTheFile(file, ref temp.x, ref temp.y, ref temp.z))
        {
            print("OOPS2");
        }
        boi.transform.position = temp;
    }
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Q))
        {
            save();
        }

        if (Input.GetKeyDown(KeyCode.E))
        {
            load();
        }
    }
}
