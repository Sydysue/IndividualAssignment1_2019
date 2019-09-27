using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Move : MonoBehaviour
{
    public float speed;
    private CharacterController control;
    // Start is called before the first frame update
    void Start()
    {
        control = GetComponent<CharacterController>();
    }

    // Update is called once per frame
    void Update()
    {
        float leftRight = Input.GetAxis("Horizontal");   
        float upDown= Input.GetAxis("Vertical");

        Vector3 movement = new Vector3();

        movement.z = upDown;
        movement.x = leftRight;
        movement.Normalize();
        movement *= Time.deltaTime * speed;
        control.Move(movement);
    }
}
