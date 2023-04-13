package Line.Linked;

public class CircleLinkList<E> extends LinkList<E>{
    protected void reCircle(){
        Node(this.size-1).next=this.head;
    }

    /**
     * 只有在增加和删除的时候会破坏循环结构
     * 设置好维护循环接口的调用时机
     */
    @Override
    public void add(int index, E element) {
        super.add(index, element);
        if (index==0&&index==size-1)
            reCircle();
    }
}
