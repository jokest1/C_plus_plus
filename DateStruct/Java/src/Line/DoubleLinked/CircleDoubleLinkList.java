package Line.DoubleLinked;

public class CircleDoubleLinkList <E> extends DoubleLinkList<E>{
    @Override
    protected void reCircle() {
        if (head!=null&&tail!=null){
            head.prev=tail;
            tail.next=head;
        }
    }
}
