package Line.Array;

import Line.AbstractLine;

public class Array <E> extends AbstractLine<E> {
    /**
     * 设置数组的首地址
     * 设置默认的最小容量
     * 记录容量有多少
     */
    protected E[] dates;
    protected int capacity;
    protected static final int DEFAULT_CAPACITY=10;
    /**
     * 无参数和带参数构造，参数用来设置大小最小为默认大小
     */
    public Array() {
        this(DEFAULT_CAPACITY);
    }
    public Array(int capacity) {
        int newCapacity=capacity>DEFAULT_CAPACITY?capacity:DEFAULT_CAPACITY;
        dates= (E[]) new Object[newCapacity];
        this.capacity =newCapacity;
    }

    /**
     * 内部的工具接口用来检查是否还用足够的空间以1.5倍扩容
     */
    protected void CheckCapacity(){
        if (size+1>this.capacity){
            int newCapacity=(this.capacity)+(this.capacity>>1);
            E[] temp = (E[]) new Object[newCapacity];
            for (int i=0;i<this.size;i++){
                temp[i]=this.dates[i];
            }
            this.dates=temp;
        }
    }
    @Override
    public void add(int index, E element) {
        checkIndex(index);
        CheckCapacity();
        for (int i=size;i>index;i--){
            this.dates[i]=this.dates[i-1];
        }
        this.dates[index]=element;
        this.size++;
    }

    @Override
    public E remove(int index) {
        E old=get(index);
        this.size--;
        for (int i=index;i<this.size;i++){
            this.dates[i]=this.dates[i+1];
        }
        return old;
    }

    @Override
    public E get(int index) {
        checkIndex(index);
        return this.dates[index];
    }

    @Override
    public void set(int index, E element) {
        checkIndex(index);
        this.dates[index]=element;
    }

    @Override
    public int indexOf(E element) {
        if (element==null){
            for (int i = 0; i < this.size; i++) {
                if (this.dates[i]==null){
                    return i;
                }
            }
        }else {
            for (int i = 0; i < this.size; i++) {
                if (this.dates[i].equals(element)){
                    return i;
                }
            }
        }
        return ELEMENT_NOT_EXIST;
    }
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("size:").append(size).append(",[");
        for (int i = 0; i < size; i++) {
            if (i!=0)
                stringBuilder.append(",");
            stringBuilder.append(dates[i]);
        }
        stringBuilder.append("]");
        return stringBuilder.toString();
    }
}
