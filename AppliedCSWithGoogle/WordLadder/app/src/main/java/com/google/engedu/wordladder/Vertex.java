package com.google.engedu.wordladder;

import java.util.ArrayList;

public class Vertex {
    private ArrayList<Edge> neighbors;
    private String label;

    public Vertex(String label) {
        this.label = label;
        this.neighbors = new ArrayList<Edge>();
    }

    public void addNeighbor(Edge edge) {
        if (!this.neighbors.contains(edge)) {
            this.neighbors.add(edge);
        }
    }

    public boolean containsNeighbor(Edge other) {
        return this.neighbors.contains(other);
    }

    public Edge getNeighbor(int index) {
        return this.neighbors.get(index);
    }

    Edge removeNeighbor(int index) {
        return this.neighbors.remove(index);
    }

    public void removeNeighbor(Edge edge) {
        this.neighbors.remove(edge);
    }

    public int getNeighborCount() {
        return this.neighbors.size();
    }

    public String getLabel() {
        return this.label;
    }

    public String toString() {
        return "Vertex " + label;
    }

    public int hashCode() {
        return this.label.hashCode();
    }

    public boolean equals(Object other) {
        if(other instanceof Vertex) {
            Vertex v = (Vertex)other;
            return this.label.equals(v.label);
        }
        return false;
    }

    public ArrayList<Edge> getNeighbors() {
        return new ArrayList<Edge>(this.neighbors);
    }
}
