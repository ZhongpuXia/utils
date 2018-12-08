#!/usr/bin/env python
#encoding:utf-8

import unittest
import numpy as np

import keras.backend as K
import tensorflow as tf
from keras.models import Model
from keras import layers

import sys
sys.path.append("..")
from common.freeze_tensorflow import freeze_graph
from common.freeze_tensorflow import save_freeze_graph
from common.freeze_tensorflow import load_freeze_graph

class TestFreezeKerasModel(unittest.TestCase):
    """
    """
    def setUp(self):
        tf.reset_default_graph()
        inp = layers.Input(shape=(10,), name="input")
        dense1 = layers.Dense(10, activation='tanh', name='dense_1')(inp)
        dense2 = layers.Dense(1, name="dense_2")(dense1)
        out = layers.Activation('sigmoid', name='pred')(dense2)
        model = Model(inputs=inp, outputs=out)

        self._input_name = [inp.op.name for inp in model.inputs]
        self._output_name = [out.op.name for out in model.outputs]
        self._input_value = np.random.random((2, 10))
        self._output_value = model.predict(self._input_value)

        sess = K.get_session()
        graph = freeze_graph(sess, output_names=self._output_name)
        #print(graph)
        save_freeze_graph(graph, "./freeze_keras.pb")
    
    def test_load(self):
        graph = load_freeze_graph("./freeze_keras.pb")
        #print(graph.get_operations())
        x = graph.get_tensor_by_name("import/" + self._input_name[0] + ":0")
        y = graph.get_tensor_by_name("import/" + self._output_name[0] + ":0")
        with tf.Session(graph=graph) as sess:
            y_pred = sess.run(y, feed_dict={x: self._input_value})
        print("y: ", self._output_value)
        print("y_pred: ", y_pred)

if __name__ == "__main__":
    unittest.main()
