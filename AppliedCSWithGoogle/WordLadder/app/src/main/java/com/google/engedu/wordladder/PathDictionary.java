/* Copyright 2016 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.google.engedu.wordladder;

import android.util.AtomicFile;
import android.util.Log;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Queue;

import static android.content.ContentValues.TAG;

public class PathDictionary {
    private static final int MAX_WORD_LENGTH = 4;
    private static HashSet<String> words = new HashSet<>();
    private static HashSet<Vertex> vertices = new HashSet<>();
    private static Graph graph;

    public PathDictionary(InputStream inputStream) throws IOException {
        if (inputStream == null) {
            return;
        }
        Log.i("Word ladder", "Loading dict");
        BufferedReader in = new BufferedReader(new InputStreamReader(inputStream));
        String line = null;
        Log.i("Word ladder", "Loading dict");
        while((line = in.readLine()) != null) {
            String word = line.trim();
            if (word.length() > MAX_WORD_LENGTH) {
                continue;
            }
            words.add(word);
        }
        for (String word: words) {
            if (word.equals("fire")) {
                Log.i(TAG, "PathDictionary: " + "firefound");
            }
            Vertex vertex = new Vertex(word);
            vertices.add(vertex);
        }
        graph = new Graph(vertices);
        buildGraph();
    }

    private void buildGraph() {
        for (Vertex firstWord: vertices) {
            for (Vertex secondWord: vertices) {
                if (areWordsNeighbors(firstWord.getLabel(), secondWord.getLabel())) {
                    graph.addEdge(firstWord, secondWord);
                }
            }
        }
    }

    private boolean areWordsNeighbors(String first, String second) {
        if (first.length() != second.length()) {
            return false;
        }
        int differingCharacters = 0;
        for (int i = 0; i < first.length(); i++) {
            if (first.charAt(i) != second.charAt(i)) {
                differingCharacters += 1;
                if (differingCharacters > 1) {
                    return false;
                }
            }
        }
        return differingCharacters == 1;
    }

    public boolean isWord(String word) {
        return words.contains(word.toLowerCase());
    }

    private ArrayList<String> neighbours(String word) {
        ArrayList<String> allNeighbors = new ArrayList<>();
        Vertex vertex = graph.getVertex(word);
        for (int i = 0; i < vertex.getNeighborCount(); i++) {
            Edge edge = vertex.getNeighbor(i);
            String label = edge.getTwo().getLabel();
            allNeighbors.add(label);
        }
        return allNeighbors;
    }

    public String[] findPath(String start, String end) {
        if (!isWord(start) || !isWord(end)) {
            return null;
        }
        ArrayDeque<ArrayList<String>> queue = new ArrayDeque<>();
        ArrayList<String> startingArray = new ArrayList<>();
        startingArray.add(start);
        queue.add(startingArray);
        while (!queue.isEmpty()) {
            ArrayList<String> path = queue.removeFirst();
            int step = 1;
            for (String p: path) {
                Log.i(TAG, "" + step + ".  " + p);
                step += 1;
            }
            String word = path.get(path.size() - 1);
            ArrayList<String> nextNeighbors;
            nextNeighbors = this.neighbours(word);
            HashSet<String> visited = new HashSet<>(path);
            for (String neighbor: nextNeighbors) {
                if (!visited.contains(neighbor)) {
                    ArrayList<String> nextPath = new ArrayList<>();
                    nextPath.addAll(path);
                    nextPath.add(neighbor);
                    if (neighbor.equals(end)) {
                        String[] result = new String[nextPath.size()];
                        result = nextPath.toArray(result);
                        return result;
                    }
                    queue.add(nextPath);
                }
            }
    }
        return null;
    }
}
