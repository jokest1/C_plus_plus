package Line;

public abstract class  AbstractLine<E> implements LineList<E>{
    /**
     * 将共有的部分抽取出来做一个父类
     * 其中查看容量和判空是公用的方法，尾插入、尾删除、元素修改、包含可以委派调用
     */
    protected int size;
    @Override
    public int size() {
        return size;
    }

    @Override
    public boolean isEmpty() {
        return size==0;
    }

    @Override
    public void clear() {
        size=0;
    }

    @Override
    public void add(E element) {
        add(size,element);
    }

    @Override
    public E remove() {
        return remove(size-1);
    }

    @Override
    public void set(E element, E newElement) {
        set(indexOf(element),newElement);
    }

    @Override
    public boolean contains(E element) {
        return indexOf(element)!=ELEMENT_NOT_EXIST;
    }

    @Override
    public abstract void add(int index, E element);
    @Override
    public abstract E remove(int index);
    @Override
    public abstract E get(int index);
    @Override
    public abstract void set(int index, E element);
    @Override
    public abstract int indexOf(E element);

    /**
     * 内部检查索引是否合法的工具类
     * @param index
     */
    protected void checkIndex(int index){
        if (index<0||index>size)
            throw new OutOfMemoryError("index越界错误:"+index);
    }
}
