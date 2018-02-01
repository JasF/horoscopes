logs = require('../common/logger').getLogger();
var gumbo = require("gumbo-parser");

var zodiacKey = ""
var parameters = {}
var textStorage = ""
var dateStorage = ""

function invokeDateTextFromTree(tree) {
    for (var i = 0; i < tree.childNodes.length; i++) {
        var child = tree.childNodes[i];
        if (child.nodeType == 1) {
            invokeDateTextFromTree(child)
        }
        else if (child.nodeType == 3 /*3 == Text*/) {
            dateStorage += child.textContent
        }
    }
}

function invokeTextFromTreeWithZodiacKey(tree, key) {
    var classValue = ""
    if (tree.nodeName == "p") {
        for (var i = 0; i < tree.attributes.length; i++) {
            var attr = tree.attributes[i];
            if (attr.name == "class") {
                classValue = attr.value
            }
        }
        parameters.paragraph = true;
        if (classValue.length) {
            parameters[classValue] = true;
        }
    }
    
    if (!key.length || classValue.length > 0) {
        return
    }
    
    for (var i = 0; i < tree.childNodes.length; i++) {
        var child = tree.childNodes[i];
        if (child.nodeType == 1 /*1 == Element*/) {
            invokeTextFromTreeWithZodiacKey(child, key)
        }
        else if (child.nodeType == 3 /*3 == Text*/) {
            textStorage += child.textContent
        }
    }
    
    if (tree.nodeName == "p") {
        parameters.paragraph = false;
        if (classValue.length) {
            delete parameters[classValue];
        }
    }
}

function ruInvokePayloadData(tree, completion) {
    if (tree.nodeName == "div") {
        for (var y = 0; y < tree.attributes.length; y++) {
            attribute = tree.attributes[y];
            if (attribute.name == "class" && attribute.value == "horoBlock") {
                textStorage = ""
                logs.debug('**** pre invokeTextFromTreeWithZodiacKey')
                invokeTextFromTreeWithZodiacKey(tree, zodiacKey)
            }
            else if (attribute.name == "id" && attribute.value == "type2") {
                dateStorage = ""
                invokeDateTextFromTree(tree);
                dateStorage = dateStorage.trim()
                logs.debug(dateStorage);
            }
        }
    }
    if (tree.nodeName == "body") {
        for (var y = 0; y < tree.attributes.length; y++) {
            attribute = tree.attributes[y];
            if (attribute.name == "class") {
                zodiacKey = attribute.value
            }
        }
    }
    
    for (var i = 0; i < tree.childNodes.length; i++) {
        var child = tree.childNodes[i];
        if (child.nodeType == 1 /*1 == Element*/) {
            ruInvokePayloadData(child, null)
        }
        
    }
    if (completion != null) {
        completion(zodiacKey, textStorage)
    }
}

exports.parse = function (text, completion) {
    headIndex = text.indexOf("<head>")
    if (headIndex > 0) {
        text = text.substr(headIndex)
    }
    var tree = gumbo(text);
    var root = tree["root"]
    logs.debug('RU root: ' + root);
    ruInvokePayloadData(root, function (zodiacName, predictionText) {
                        logs.debug('zodiacName: ' + zodiacName + '; predictionText length: ' + (predictionText != null) ? predictionText.length : 0)
                        completion(zodiacName, predictionText)
                 });
}
