// Module['print'] = function(text) { alert('stdout: ' + text) };
Module['logReadFiles'] = true;
Module['preInit'] = [
    () => console.log("preInit() called!")
]