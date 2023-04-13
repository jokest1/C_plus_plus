package Line.SpecialLine.stack;

import Line.Array.Array;

public class StackLine <E>implements Stack<E>{
    protected Array<E> sta;

    @Override
    public int size() {
        return sta.size();
    }

    @Override
    public boolean isEmpty() {
        return sta.isEmpty();
    }

    @Override
    public void clear() {
        sta.clear();
    }

    @Override
    public void push(E element) {
        sta.add(element);
    }

    @Override
    public E pop() {
        return sta.remove();
    }

    @Override
    public E peek() {
        return sta.get(size()-1);
    }
}
