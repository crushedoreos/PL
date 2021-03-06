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
public class circular_linked_list {   
    public class Node{  
        int data;  
        Node next;  
        public Node(int data) {  
            this.data = data;  
        }  
    }   
    public Node head = null;  
    public Node tail = null;   
    public void add(int data){   
        Node newNode = new Node(data);    
        if(head == null) {    
            head = newNode;  
            tail = newNode;  
            newNode.next = head;  
        }  
        else {    
            tail.next = newNode;   
            tail = newNode;  
            tail.next = head;  
        }  
    }   
    public void display() {  
        Node current = head;  
        if(head == null) {  
            System.out.println("List is empty");  
        }  
        else {  
            System.out.println("Nodes of the circular linked list: ");  
             do{   
                System.out.print(" "+ current.data);  
                current = current.next;  
            }while(current != head);  
            System.out.println();  
        }  
    }   
    public static void main(String[] args) {  
        circular_linked_list cl = new circular_linked_list();  
        cl.add(1);  
        cl.add(2);  
        cl.add(3);  
        cl.add(4);   
        cl.display();  
    }  
}  