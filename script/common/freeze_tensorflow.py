import tensorflow as tf

def freeze_graph(sess, keep_var_names=None, output_names=None, clear_devices=True):
    from tensorflow.python.framework.graph_util import convert_variables_to_constants
    graph = sess.graph
    with graph.as_default():
        graph_def = graph.as_graph_def()
        freeze_var_names = list(set(v.op.name for v in tf.global_variables()).difference(keep_var_names or set()))
        output_names = output_names or []
        assert len(output_names) > 0
        #output_names +=[v.op.name for v in tf.global_variables()]
        #print(sess.graph.get_operations())
        
        if clear_devices:
            for node in graph_def.node:
                node.device = ""
        freeze_graph = convert_variables_to_constants(sess, graph_def, output_names, freeze_var_names)
        return freeze_graph
    
def save_freeze_graph(graph_def, path="./freeze_graph.pb"):
    import os
    dir_name = os.path.dirname(path)
    file_name = os.path.basename(path)
    tf.train.write_graph(graph_def, dir_name, file_name, as_text=False)
    
def load_freeze_graph(filename): 
    with tf.gfile.GFile(filename, 'rb') as f:
        graph_def = tf.GraphDef()
        graph_def.ParseFromString(f.read())
    with tf.Graph().as_default() as graph:
        tf.import_graph_def(graph_def)
        return graph
