package Line.Linked;

import Line.AbstractLine;

public class LinkList<E> extends AbstractLine<E> {
    @Override
    public void clear() {
        super.clear();
        this.head=null;
    }

    /**
     *设计好基础结点，包含一个元素和指向下一个节点的指针
     * 然后设计一个头结点
     */
    protected static class base_Node<E>{
        E element;
        base_Node<E> next;
        public base_Node(E element, base_Node<E> next) {
            this.element = element;
            this.next = next;
        }

        @Override
        public String toString() {
            return element+"->"+(next!=null?next.element:"null");
        }
    }
    protected base_Node<E> head;

    /**
     *设计内部使用的工具接口
     * Node(index)接口，通过索引返回指向这个结点的指针
     */
    protected base_Node<E> Node(int index){
        checkIndex(index);
        base_Node<E> node = this.head;
        while (index!=0){
            index--;
            node=node.next;
        }
        return node;
    }

    /**
     *添加分为两种情况分别是头部添加、非头部添加
     * 头部添加直接用head指针就好了
     * 非头部需要找到添加前的那个结点
     */
    @Override
    public void add(int index, E element) {
        if (index==0){
            head=new base_Node<>(element,head);
        }else{
            base_Node<E> node = Node(index - 1);
            node.next=new base_Node<>(element,node.next);
        }
        this.size++;
    }
    /**
     * 将删除分为两种情况：删除的是头、删除的是非头
     *  非头  调用内部工具类然后找到删除前一个
     *  头   直接调整头指针指向
     */
    @Override
    public E remove(int index) {
        E old=null;
        if (this.size==0) return null;
        if (index==0){
            old=this.head.element;
            this.head=this.head.next;
        }else{
            base_Node<E> node = Node(index - 1);
            old=node.next.element;
            node.next=node.next.next;
        }
        size--;
        if (index==0&&index==size)
            reCircle();
        return old;
    }

    /**
     * 调用工具类直接解决
     */
    @Override
    public E get(int index) {
        return Node(index).element;
    }

    @Override
    public void set(int index, E element) {
        Node(index).element=element;
    }

    @Override
    public int indexOf(E element) {
        if (element==null){
            base_Node<E> node = this.head;
            for (int i = 0; i < this.size; i++,node=node.next) {
                if (node.element==null){
                    return i;
                }
            }
        }else {
            base_Node<E> node = this.head;
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
    protected void reCircle(){}
}
