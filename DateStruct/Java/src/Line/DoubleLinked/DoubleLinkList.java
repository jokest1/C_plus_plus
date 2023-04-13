package Line.DoubleLinked;

import Line.AbstractLine;
import Line.Linked.LinkList;

public class DoubleLinkList <E> extends AbstractLine<E> {
    protected static class base_Node<E>{
        E element;
        base_Node<E> prev;
        base_Node<E> next;

        public base_Node(base_Node<E> prev,E element,  base_Node<E> next) {
            this.element = element;
            this.prev = prev;
            this.next = next;
        }

        @Override
        public String toString() {
            return (prev!=null?prev.element:"null")+"<-"+element+"->"+(next!=null?next.element:"null");
        }
    }
    protected base_Node<E> head;
    protected base_Node<E> tail;

    /**
     *因为双向链表是由头尾指针的，所以寻找元素可以从双端寻找
     * 对于多余一半的索引从后方寻找，反之
     */
    protected base_Node<E> node(int index){
        base_Node<E> node;
        if (index<=(this.size>>1)){
            node = this.head;
            for (int i = 0; i < index; i++,node=node.next) {}
        }else {
            node = this.tail;
            for (int i = size - 1; i > index; i--, node = node.prev) {}
        }
        return node;
    }

    @Override
    public void clear() {
        super.clear();
        head=tail=null;
    }

    /**
     *添加元素分为两部分，头插入和非头插入
     * 之后将头插入再分为两种状况：没有元素的头插入、有元素的头插入
     * 非头插入同样分为两种：尾插入、中间插入
     * 在尾插入和头插入的地方留好扩展接口reCircle
     */
    @Override
    public void add(int index, E element) {
        checkIndex(index);
        if (index==0){
            if (size==0){
                head=new base_Node<>(null,element,head);
                tail=head;
                reCircle();
            }else{
                head.prev=new base_Node<>(null,element,head);
                head=head.prev;
            }
        }else{
            if(index==size){
                tail.next=new base_Node<>(tail,element,null);
                tail=tail.next;
                reCircle();
            }else{
                base_Node<E> node = node(index);
                node.prev=new base_Node<>(node.prev,element,node);
                node.prev.prev.next=node.prev;
            }
        }
        size++;
    }

    protected void reCircle() {}

    /**
     *删除也分为了四种状况分别是头删除的两种和非头删除两种
     * 头删除时候只有一个元素、头删除不止一个元素
     * 尾删除时候只有一个元素，不止一个元素
     */
    @Override
    public E remove(int index) {
        checkIndex(index);
        E old=null;
        if (index==0){
            old=head.element;
            if (size==1){
                head=null;
                tail=null;
            }else{
                head=head.next;
                head.prev=null;
                reCircle();
            }
        }else{
            if (index==size-1){
                old=tail.element;
                    tail=tail.prev;
                    tail.next=null;
                    reCircle();
            }else{
                base_Node<E> node = node(index - 1);
                old=node.next.element;
                node.next=node.next.next;
                node.next.prev=node;
            }
        }
        size--;
        return old;
    }

    @Override
    public E get(int index) {
        return node(index).element;
    }

    @Override
    public void set(int index, E element) {
        node(index).element=element;
    }

    @Override
    public int indexOf(E element) {
        base_Node<E> node = this.head;
        if (element==null){
            for (int i = 0; i < this.size; i++,node=node.next) {
                if (node.element==null){
                    return i;
                }
            }
        }else {
            for (int i = 0; i < this.size; i++,node=node.next) {
                if (node.element.equals(element)){
                    return i;
                }
            }
        }
        return ELEMENT_NOT_EXIST;
    }
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("size:").append(size).append(",[");
        base_Node<E> node = this.head;
        for (int i = 0; i < size; i++,node=node.next) {
            if (i!=0)
                stringBuilder.append(",");
            stringBuilder.append(node.toString());
        }
        stringBuilder.append("]");
        return stringBuilder.toString();
    }
}
