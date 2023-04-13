package Line.SpecialLine.Queue;

import Line.Array.Array;

public class Deque <E>implements Queue<E>{
    protected Array<E> Dque;
    @Override
    public int size() {
        return Dque.size();
    }

    @Override
    public void clear() {
        Dque.clear();
    }

    @Override
    public boolean isEmpty() {
        return Dque.isEmpty();
    }

    @Override
    public void push_back(E element) {
        Dque.add(element);
    }

    @Override
    public void push_head(E element) {
        Dque.add(0,element);
    }

    @Override
    public E peek_head() {
        return Dque.get(0);
    }

    @Override
    public E peek_back() {
        return Dque.get(size()-1);
    }

    @Override
    public E pop_head() {
        return Dque.remove(0);
    }

    @Override
    public E pop_back() {
        return Dque.remove(size()-1);
    }

    @Override
    public void insert(int index, E element) {
        Dque.add(index,element);
    }
}
