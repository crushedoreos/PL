/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package placement;

/**
 *
 * @author racha
 */
import java.util.*;
 
class check_circular
{
static class Node
{
    int data;
    Node next;
}
static boolean isCircular( Node head)
{
    if (head == null)
    return true;
    Node node = head.next;
    while (node != null && node != head)
    node = node.next;
    return (node == head);
}
static Node newNode(int data)
{
    Node temp = new Node();
    temp.data = data;
    temp.next = null;
    return temp;
}
public static void main(String args[])
{
    Node head = newNode(1);
    head.next = newNode(2);
    head.next.next = newNode(3);
    head.next.next.next = newNode(4);
    System.out.print(isCircular(head)? "Yes\n" :
                    "No\n" );
    head.next.next.next.next = head;
    System.out.print(isCircular(head)? "Yes\n" :
                    "No\n" );
}
}