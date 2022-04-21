---
title: 测试文章 - ECharts
tags:
  - 测试
top: 0
date: 1000-01-01 00:00:04
comments: false
---

示例来自 <https://echarts.apache.org/examples/zh/index.html>

<!-- more -->

## Basic line chart

{% echarts 400 '85%' %}
option = {
xAxis: {
type: 'category',
data: ['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun']
},
yAxis: {
type: 'value'
},
series: [{
data: [820, 932, 901, 934, 1290, 1330, 1320],
type: 'line'
}]
};
{% endecharts %}

## Stacked area chart

{% echarts 400 '85%' %}
option = {
title: {
text: '堆叠区域图'
},
tooltip: {
trigger: 'axis',
axisPointer: {
type: 'cross',
label: {
backgroundColor: '#6a7985'
}
}
},
legend: {
data: ['邮件营销', '联盟广告', '视频广告', '直接访问', '搜索引擎']
},
toolbox: {
feature: {
saveAsImage: {}
}
},
grid: {
left: '3%',
right: '4%',
bottom: '3%',
containLabel: true
},
xAxis: [
{
type: 'category',
boundaryGap: false,
data: ['周一', '周二', '周三', '周四', '周五', '周六', '周日']
}
],
yAxis: [
{
type: 'value'
}
],
series: [
{
name: '邮件营销',
type: 'line',
stack: '总量',
areaStyle: {},
data: [120, 132, 101, 134, 90, 230, 210]
},
{
name: '联盟广告',
type: 'line',
stack: '总量',
areaStyle: {},
data: [220, 182, 191, 234, 290, 330, 310]
},
{
name: '视频广告',
type: 'line',
stack: '总量',
areaStyle: {},
data: [150, 232, 201, 154, 190, 330, 410]
},
{
name: '直接访问',
type: 'line',
stack: '总量',
areaStyle: {},
data: [320, 332, 301, 334, 390, 330, 320]
},
{
name: '搜索引擎',
type: 'line',
stack: '总量',
label: {
normal: {
show: true,
position: 'top'
}
},
areaStyle: {},
data: [820, 932, 901, 934, 1290, 1330, 1320]
}
]
};
{% endecharts %}

## Line easing visualizing

{% echarts 400 '85%' %}
var easingFuncs = {
linear: function (k) {
return k;
},
quadraticIn: function (k) {
return k _k;
},
quadraticOut: function (k) {
return k_ (2 - k);
},
quadraticInOut: function (k) {
if ((k _= 2) < 1) { return 0.5_ k _k; }
return -0.5_ (--k _(k - 2) - 1);
},
cubicIn: function (k) {
return k_ k _k;
},
cubicOut: function (k) {
return --k_ k _k + 1;
},
cubicInOut: function (k) {
if ((k_= 2) < 1) { return 0.5 _k_ k _k; }
return 0.5_ ((k -= 2) _k_ k + 2);
},
quarticIn: function (k) {
return k _k_ k _k;
},
quarticOut: function (k) {
return 1 - (--k_ k _k_ k);
},
quarticInOut: function (k) {
if ((k _= 2) < 1) { return 0.5_ k _k_ k _k; }
return -0.5_ ((k -= 2) _k_ k _k - 2);
},
quinticIn: function (k) {
return k_ k _k_ k _k;
},
quinticOut: function (k) {
return --k_ k _k_ k _k + 1;
},
quinticInOut: function (k) {
if ((k_= 2) < 1) { return 0.5 _k_ k _k_ k _k; }
return 0.5_ ((k -= 2) _k_ k _k_ k + 2);
},
sinusoidalIn: function (k) {
return 1 - Math.cos(k _Math.PI / 2);
},
sinusoidalOut: function (k) {
return Math.sin(k_ Math.PI / 2);
},
sinusoidalInOut: function (k) {
return 0.5 _(1 - Math.cos(Math.PI_ k));
},
exponentialIn: function (k) {
return k === 0 ? 0 : Math.pow(1024, k - 1);
},
exponentialOut: function (k) {
return k === 1 ? 1 : 1 - Math.pow(2, -10 _k);
},
exponentialInOut: function (k) {
if (k === 0) {
return 0;
}
if (k === 1) {
return 1;
}
if ((k_= 2) < 1) {
return 0.5 _Math.pow(1024, k - 1);
}
return 0.5_ (-Math.pow(2, -10 _(k - 1)) + 2);
},
circularIn: function (k) {
return 1 - Math.sqrt(1 - k_ k);
},
circularOut: function (k) {
return Math.sqrt(1 - (--k _k));
},
circularInOut: function (k) {
if ((k_= 2) < 1) { return -0.5 _(Math.sqrt(1 - k_ k) - 1); }
return 0.5 _(Math.sqrt(1 - (k -= 2)_ k) + 1);
},
elasticIn: function (k) {
var s;
var a = 0.1;
var p = 0.4;
if (k === 0) { return 0; }
if (k === 1) { return 1; }
if (!a || a < 1) { a = 1; s = p / 4; }
else { s = p _Math.asin(1 / a) / (2_ Math.PI); }
return -(a _Math.pow(2, 10_ (k -= 1)) _Math.sin((k - s)_ (2 _Math.PI) / p));
},
elasticOut: function (k) {
var s;
var a = 0.1;
var p = 0.4;
if (k === 0) { return 0; }
if (k === 1) { return 1; }
if (!a || a < 1) { a = 1; s = p / 4; }
else { s = p_ Math.asin(1 / a) / (2 _Math.PI); }
return (a_ Math.pow(2, -10 _k)_ Math.sin((k - s) _(2_ Math.PI) / p) + 1);
},
elasticInOut: function (k) {
var s;
var a = 0.1;
var p = 0.4;
if (k === 0) { return 0; }
if (k === 1) { return 1; }
if (!a || a < 1) { a = 1; s = p / 4; }
else { s = p _Math.asin(1 / a) / (2_ Math.PI); }
if ((k _= 2) < 1) {
return -0.5_ (a _Math.pow(2, 10_ (k -= 1)) _Math.sin((k - s)_ (2 _Math.PI) / p));
}
return a_ Math.pow(2, -10 _(k -= 1))_ Math.sin((k - s) _(2_ Math.PI) / p) \* 0.5 + 1;

    },

    // 在某一动画开始沿指示的路径进行动画处理前稍稍收回该动画的移动
    backIn: function (k) {
        var s = 1.70158;
        return k * k * ((s + 1) * k - s);
    },
    backOut: function (k) {
        var s = 1.70158;
        return --k * k * ((s + 1) * k + s) + 1;
    },
    backInOut: function (k) {
        var s = 1.70158 * 1.525;
        if ((k *= 2) < 1) { return 0.5 * (k * k * ((s + 1) * k - s)); }
        return 0.5 * ((k -= 2) * k * ((s + 1) * k + s) + 2);
    },

    // 创建弹跳效果
    bounceIn: function (k) {
        return 1 - easingFuncs.bounceOut(1 - k);
    },
    bounceOut: function (k) {
        if (k < (1 / 2.75)) { return 7.5625 * k * k; }
        else if (k < (2 / 2.75)) { return 7.5625 * (k -= (1.5 / 2.75)) * k + 0.75; }
        else if (k < (2.5 / 2.75)) { return 7.5625 * (k -= (2.25 / 2.75)) * k + 0.9375; }
        else { return 7.5625 * (k -= (2.625 / 2.75)) * k + 0.984375; }
    },
    bounceInOut: function (k) {
        if (k < 0.5) { return easingFuncs.bounceIn(k * 2) * 0.5; }
        return easingFuncs.bounceOut(k * 2 - 1) * 0.5 + 0.5;
    }

};

var N_POINT = 30;

var grids = [];
var xAxes = [];
var yAxes = [];
var series = [];
var titles = [];
var count = 0;
echarts.util.each(easingFuncs, function (easingFunc, name) {
var data = [];
for (var i = 0; i <= N_POINT; i++) {
var x = i / N_POINT;
var y = easingFunc(x);
data.push([x, y]);
}
grids.push({
show: true,
borderWidth: 0,
backgroundColor: '#fff',
shadowColor: 'rgba(0, 0, 0, 0.3)',
shadowBlur: 2
});
xAxes.push({
type: 'value',
show: false,
min: 0,
max: 1,
gridIndex: count
});
yAxes.push({
type: 'value',
show: false,
min: -0.4,
max: 1.4,
gridIndex: count
});
series.push({
name: name,
type: 'line',
xAxisIndex: count,
yAxisIndex: count,
data: data,
showSymbol: false,
animationEasing: name,
animationDuration: 1000
});
titles.push({
textAlign: 'center',
text: name,
textStyle: {
fontSize: 12,
fontWeight: 'normal'
}
});
count++;
});

var rowNumber = Math.ceil(Math.sqrt(count));
echarts.util.each(grids, function (grid, idx) {
grid.left = ((idx % rowNumber) / rowNumber _100 + 0.5) + '%';
grid.top = (Math.floor(idx / rowNumber) / rowNumber_ 100 + 0.5) + '%';
grid.width = (1 / rowNumber _100 - 1) + '%';
grid.height = (1 / rowNumber_ 100 - 1) + '%';

    titles[idx].left = parseFloat(grid.left) + parseFloat(grid.width) / 2 + '%';
    titles[idx].top = parseFloat(grid.top) + '%';

});

option = {
title: titles.concat([{
text: 'Different Easing Functions',
top: 'bottom',
left: 'center'
}]),
grid: grids,
xAxis: xAxes,
yAxis: yAxes,
series: series
};
{% endecharts %}

## Try dragging these points

{% echarts 400 '85%' %}
var symbolSize = 20;
var data = [[15, 0], [-50, 10], [-56.5, 20], [-46.5, 30], [-22.1, 40]];

option = {
title: {
text: 'Try Dragging these Points'
},
tooltip: {
triggerOn: 'none',
formatter: function (params) {
return 'X: ' + params.data[0].toFixed(2) + '<br>Y: ' + params.data[1].toFixed(2);
}
},
grid: {
},
xAxis: {
min: -100,
max: 80,
type: 'value',
axisLine: {onZero: false}
},
yAxis: {
min: -30,
max: 60,
type: 'value',
axisLine: {onZero: false}
},
dataZoom: [
{
type: 'slider',
xAxisIndex: 0,
filterMode: 'empty'
},
{
type: 'slider',
yAxisIndex: 0,
filterMode: 'empty'
},
{
type: 'inside',
xAxisIndex: 0,
filterMode: 'empty'
},
{
type: 'inside',
yAxisIndex: 0,
filterMode: 'empty'
}
],
series: [
{
id: 'a',
type: 'line',
smooth: true,
symbolSize: symbolSize,
data: data
}
]
};

setTimeout(function () {
// Add shadow circles (which is not visible) to enable drag.
myChart.setOption({
graphic: echarts.util.map(data, function (item, dataIndex) {
return {
type: 'circle',
position: myChart.convertToPixel('grid', item),
shape: {
cx: 0,
cy: 0,
r: symbolSize / 2
},
invisible: true,
draggable: true,
ondrag: echarts.util.curry(onPointDragging, dataIndex),
onmousemove: echarts.util.curry(showTooltip, dataIndex),
onmouseout: echarts.util.curry(hideTooltip, dataIndex),
z: 100
};
})
});
}, 0);

window.addEventListener('resize', updatePosition);

myChart.on('dataZoom', updatePosition);

function updatePosition() {
myChart.setOption({
graphic: echarts.util.map(data, function (item, dataIndex) {
return {
position: myChart.convertToPixel('grid', item)
};
})
});
}

function showTooltip(dataIndex) {
myChart.dispatchAction({
type: 'showTip',
seriesIndex: 0,
dataIndex: dataIndex
});
}

function hideTooltip(dataIndex) {
myChart.dispatchAction({
type: 'hideTip'
});
}

function onPointDragging(dataIndex, dx, dy) {
data[dataIndex] = myChart.convertFromPixel('grid', this.position);

    // Update data
    myChart.setOption({
        series: [{
            id: 'a',
            data: data
        }]
    });

}
{% endecharts %}

## Function plot

{% echarts 400 '85%' %}
function func(x) {
x /= 10;
return Math.sin(x) _Math.cos(x_ 2 + 1) _Math.sin(x_ 3 + 2) \* 50;
}

function generateData() {
let data = [];
for (let i = -200; i <= 200; i += 0.1) {
data.push([i, func(i)]);
}
return data;
}

option = {
animation: false,
grid: {
top: 40,
left: 50,
right: 40,
bottom: 50
},
xAxis: {
name: 'x',
minorTick: {
show: true
},
splitLine: {
lineStyle: {
color: '#999'
}
},
minorSplitLine: {
show: true,
lineStyle: {
color: '#ddd'
}
}
},
yAxis: {
name: 'y',
min: -100,
max: 100,
minorTick: {
show: true
},
splitLine: {
lineStyle: {
color: '#999'
}
},
minorSplitLine: {
show: true,
lineStyle: {
color: '#ddd'
}
}
},
dataZoom: [{
show: true,
type: 'inside',
filterMode: 'none',
xAxisIndex: [0],
startValue: -20,
endValue: 20
}, {
show: true,
type: 'inside',
filterMode: 'none',
yAxisIndex: [0],
startValue: -20,
endValue: 20
}],
series: [
{
type: 'line',
showSymbol: false,
clip: true,
data: generateData()
}
]
};
{% endecharts %}

## Dynamic data + time axis

{% echarts 400 '85%' %}
function randomData() {
now = new Date(+now + oneDay);
value = value + Math.random() \* 21 - 10;
return {
name: now.toString(),
value: [
[now.getFullYear(), now.getMonth() + 1, now.getDate()].join('/'),
Math.round(value)
]
};
}

var data = [];
var now = +new Date(1997, 9, 3);
var oneDay = 24 _3600_ 1000;
var value = Math.random() \* 1000;
for (var i = 0; i < 1000; i++) {
data.push(randomData());
}

option = {
title: {
text: '动态数据 + 时间坐标轴'
},
tooltip: {
trigger: 'axis',
formatter: function (params) {
params = params[0];
var date = new Date(params.name);
return date.getDate() + '/' + (date.getMonth() + 1) + '/' + date.getFullYear() + ' : ' + params.value[1];
},
axisPointer: {
animation: false
}
},
xAxis: {
type: 'time',
splitLine: {
show: false
}
},
yAxis: {
type: 'value',
boundaryGap: [0, '100%'],
splitLine: {
show: false
}
},
series: [{
name: '模拟数据',
type: 'line',
showSymbol: false,
hoverAnimation: false,
data: data
}]
};

setInterval(function () {

    for (var i = 0; i < 5; i++) {
        data.shift();
        data.push(randomData());
    }

    myChart.setOption({
        series: [{
            data: data
        }]
    });

}, 1000);
{% endecharts %}

## Share dataset

{% echarts 400 '85%' %}

setTimeout(function () {

    option = {
        legend: {},
        tooltip: {
            trigger: 'axis',
            showContent: false
        },
        dataset: {
            source: [
                ['product', '2012', '2013', '2014', '2015', '2016', '2017'],
                ['Matcha Latte', 41.1, 30.4, 65.1, 53.3, 83.8, 98.7],
                ['Milk Tea', 86.5, 92.1, 85.7, 83.1, 73.4, 55.1],
                ['Cheese Cocoa', 24.1, 67.2, 79.5, 86.4, 65.2, 82.5],
                ['Walnut Brownie', 55.2, 67.1, 69.2, 72.4, 53.9, 39.1]
            ]
        },
        xAxis: {type: 'category'},
        yAxis: {gridIndex: 0},
        grid: {top: '55%'},
        series: [
            {type: 'line', smooth: true, seriesLayoutBy: 'row'},
            {type: 'line', smooth: true, seriesLayoutBy: 'row'},
            {type: 'line', smooth: true, seriesLayoutBy: 'row'},
            {type: 'line', smooth: true, seriesLayoutBy: 'row'},
            {
                type: 'pie',
                id: 'pie',
                radius: '30%',
                center: ['50%', '25%'],
                label: {
                    formatter: '{b}: {@2012} ({d}%)'
                },
                encode: {
                    itemName: 'product',
                    value: '2012',
                    tooltip: '2012'
                }
            }
        ]
    };

    myChart.on('updateAxisPointer', function (event) {
        var xAxisInfo = event.axesInfo[0];
        if (xAxisInfo) {
            var dimension = xAxisInfo.value + 1;
            myChart.setOption({
                series: {
                    id: 'pie',
                    label: {
                        formatter: '{b}: {@[' + dimension + ']} ({d}%)'
                    },
                    encode: {
                        value: dimension,
                        tooltip: dimension
                    }
                }
            });
        }
    });

    myChart.setOption(option);

});
{% endecharts %}

## Les miserables

{% echarts 400 '85%' %}
myChart.showLoading();
$.get(ROOT_PATH + '/data/asset/data/les-miserables.gexf', function (xml) {
myChart.hideLoading();

    var graph = echarts.dataTool.gexf.parse(xml);
    var categories = [];
    for (var i = 0; i < 9; i++) {
        categories[i] = {
            name: '类目' + i
        };
    }
    graph.nodes.forEach(function (node) {
        node.itemStyle = null;
        node.value = node.symbolSize;
        node.symbolSize /= 1.5;
        node.label = {
            normal: {
                show: node.symbolSize > 10
            }
        };
        node.category = node.attributes.modularity_class;
    });
    option = {
        title: {
            text: 'Les Miserables',
            subtext: 'Circular layout',
            top: 'bottom',
            left: 'right'
        },
        tooltip: {},
        legend: [{
            data: categories.map(function (a) {
                return a.name;
            })
        }],
        animationDurationUpdate: 1500,
        animationEasingUpdate: 'quinticInOut',
        series: [
            {
                name: 'Les Miserables',
                type: 'graph',
                layout: 'circular',
                circular: {
                    rotateLabel: true
                },
                data: graph.nodes,
                links: graph.links,
                categories: categories,
                roam: true,
                label: {
                    position: 'right',
                    formatter: '{b}'
                },
                lineStyle: {
                    color: 'source',
                    curveness: 0.3
                }
            }
        ]
    };

    myChart.setOption(option);

}, 'xml');
{% endecharts %}

## Parallel nutrients

{% echarts 400 '85%' %}
var indices = {
name: 0,
group: 1,
id: 16
};
var schema = [
{name: 'name', index: 0},
{name: 'group', index: 1},
{name: 'protein', index: 2},
{name: 'calcium', index: 3},
{name: 'sodium', index: 4},
{name: 'fiber', index: 5},
{name: 'vitaminc', index: 6},
{name: 'potassium', index: 7},
{name: 'carbohydrate', index: 8},
{name: 'sugars', index: 9},
{name: 'fat', index: 10},
{name: 'water', index: 11},
{name: 'calories', index: 12},
{name: 'saturated', index: 13},
{name: 'monounsat', index: 14},
{name: 'polyunsat', index: 15},
{name: 'id', index: 16}
];

var groupCategories = [];
var groupColors = [];

$.get(ROOT_PATH + '/data/asset/data/nutrients.json', function (data) {
normalizeData(data);

    myChart.setOption(option = getOption(data));

});

function normalizeData(originData) {
var groupMap = {};
originData.forEach(function (row) {
var groupName = row[indices.group];
if (!groupMap.hasOwnProperty(groupName)) {
groupMap[groupName] = 1;
}
});

    originData.forEach(function (row) {
        row.forEach(function (item, index) {
            if (index !== indices.name
                && index !== indices.group
                && index !== indices.id
            ) {
                // Convert null to zero, as all of them under unit "g".
                row[index] = parseFloat(item) || 0;
            }
        });
    });

    for (var groupName in groupMap) {
        if (groupMap.hasOwnProperty(groupName)) {
            groupCategories.push(groupName);
        }
    }
    var hStep = Math.round(300 / (groupCategories.length - 1));
    for (var i = 0; i < groupCategories.length; i++) {
        groupColors.push(echarts.color.modifyHSL('#5A94DF', hStep * i));
    }

}

function getOption(data) {

    var lineStyle = {
        normal: {
            width: 0.5,
            opacity: 0.05
        }
    };

    return {
        backgroundColor: '#333',
        tooltip: {
            padding: 10,
            backgroundColor: '#222',
            borderColor: '#777',
            borderWidth: 1,
            formatter: function (obj) {
                var value = obj[0].value;
                return '<div style="border-bottom: 1px solid rgba(255,255,255,.3); font-size: 18px;padding-bottom: 7px;margin-bottom: 7px">'
                    + schema[1].name + '：' + value[1] + '<br>'
                    + schema[2].name + '：' + value[2] + '<br>'
                    + schema[3].name + '：' + value[3] + '<br>'
                    + schema[4].name + '：' + value[4] + '<br>'
                    + schema[5].name + '：' + value[5] + '<br>'
                    + schema[6].name + '：' + value[6] + '<br>';
            }
        },
        title: [
            {
                text: 'Groups',
                top: 0,
                left: 0,
                textStyle: {
                    color: '#fff'
                }
            }
        ],
        visualMap: {
            show: true,
            type: 'piecewise',
            categories: groupCategories,
            dimension: indices.group,
            inRange: {
                color: groupColors //['#d94e5d','#eac736','#50a3ba']
            },
            outOfRange: {
                color: ['#ccc'] //['#d94e5d','#eac736','#50a3ba']
            },
            top: 20,
            textStyle: {
                color: '#fff'
            },
            realtime: false
        },
        parallelAxis: [
            {dim: 16, name: schema[16].name, scale: true, nameLocation: 'end'},
            {dim: 2, name: schema[2].name, nameLocation: 'end'},
            {dim: 4, name: schema[4].name, nameLocation: 'end'},
            {dim: 3, name: schema[3].name, nameLocation: 'end'},
            {dim: 5, name: schema[5].name, nameLocation: 'end'},
            {dim: 6, name: schema[6].name, nameLocation: 'end'},
            {dim: 7, name: schema[7].name, nameLocation: 'end'},
            {dim: 8, name: schema[8].name, nameLocation: 'end'},
            {dim: 9, name: schema[9].name, nameLocation: 'end'},
            {dim: 10, name: schema[10].name, nameLocation: 'end'},
            {dim: 11, name: schema[11].name, nameLocation: 'end'},
            {dim: 12, name: schema[12].name, nameLocation: 'end'},
            {dim: 13, name: schema[13].name, nameLocation: 'end'},
            {dim: 14, name: schema[14].name, nameLocation: 'end'},
            {dim: 15, name: schema[15].name, nameLocation: 'end'}
        ],
        parallel: {
            left: 280,
            top: 20,
            // top: 150,
            // height: 300,
            width: 400,
            layout: 'vertical',
            parallelAxisDefault: {
                type: 'value',
                name: 'nutrients',
                nameLocation: 'end',
                nameGap: 20,
                nameTextStyle: {
                    color: '#fff',
                    fontSize: 14
                },
                axisLine: {
                    lineStyle: {
                        color: '#aaa'
                    }
                },
                axisTick: {
                    lineStyle: {
                        color: '#777'
                    }
                },
                splitLine: {
                    show: false
                },
                axisLabel: {
                    color: '#fff'
                },
                realtime: false
            }
        },
        animation: false,
        series: [
            {
                name: 'nutrients',
                type: 'parallel',
                lineStyle: lineStyle,
                inactiveOpacity: 0,
                activeOpacity: 0.01,
                progressive: 500,
                smooth: true,
                data: data
            }
        ]
    };

}
{% endecharts %}

## Use custom series to draw wind vectors

{% echarts 400 '85%' %}
$.getJSON(ROOT_PATH + '/data-gl/asset/data/winds.json', function (windData) {
var p = 0;
var maxMag = 0;
var minMag = Infinity;
var data = [];
for (var j = 0; j < windData.ny; j++) {
for (var i = 0; i < windData.nx; i++, p++) {
var vx = windData.data[p][0];
var vy = windData.data[p][1];
var mag = Math.sqrt(vx _ vx + vy _ vy);
// 数据是一个一维数组
// [ [经度, 维度, 向量经度方向的值, 向量维度方向的值] ]
data.push([
i / windData.nx *360 - 180,
j / windData.ny* 180 - 90,
vx,
vy,
mag
]);
maxMag = Math.max(mag, maxMag);
minMag = Math.min(mag, minMag);
}
}
data.reverse();

    myChart.setOption(option = {
        backgroundColor: '#333',
        visualMap: {
            left: 'center',
            min: minMag,
            max: maxMag,
            dimension: 4,
            inRange: {
                // color: ['green', 'yellow', 'red']
                color: ['#313695', '#4575b4', '#74add1', '#abd9e9', '#e0f3f8', '#ffffbf', '#fee090', '#fdae61', '#f46d43', '#d73027', '#a50026']
            },
            calculable: true,
            textStyle: {
                color: '#fff'
            },
            orient: 'horizontal'
        },
        geo: {
            map: 'world',
            left: 0,
            right: 0,
            top: 0,
            zoom: 1,
            silent: true,
            roam: true,
            itemStyle: {
                areaColor: '#323c48',
                borderColor: '#111'
            }
        },
        series: {
            type: 'custom',
            coordinateSystem: 'geo',
            data: data,
            encode: {
                x: 0,
                y: 0
            },
            renderItem: function (params, api) {
                var x = api.value(0), y = api.value(1), dx = api.value(2), dy = api.value(3);
                var start = api.coord([Math.max(x - dx / 5, -180), Math.max(y - dy / 5, -90)]);
                var end = api.coord([Math.min(x + dx / 5, 180), Math.min(y + dy / 5, 90)]);
                return {
                    type: 'line',
                    shape: {
                        x1: start[0], y1: start[1],
                        x2: end[0], y2: end[1]
                    },
                    style: {
                        lineWidth: 0.5,
                        stroke: api.visual('color')
                    }
                };
            },
            progressive: 2000
        }
    })

});
{% endecharts %}

## Moon

{% echarts 400 '85%' %}
option = {
globe: {
baseTexture: ROOT_PATH + '/data-gl/asset/moon-base.jpg',
heightTexture: ROOT_PATH + '/data-gl/asset/moon-bump.jpg',

        displacementScale: 0.05,
        displacementQuality: 'medium',

        environment: ROOT_PATH + '/data-gl/asset/starfield.jpg',

        shading: 'realistic',
        realisticMaterial: {
            roughness: 0.8,
            metalness: 0
        },

        postEffect: {
            enable: true,
            SSAO: {
                enable: true,
                radius: 2,
                intensity: 1,
                quality: 'high'
            }
        },
        temporalSuperSampling: {
            enable: true
        },
        light: {
            ambient: {
                intensity: 0
            },
            main: {
                intensity: 2,
                shadow: true
            },
            ambientCubemap: {
                texture: ROOT_PATH + '/data-gl/asset/pisa.hdr',
                exposure: 0,
                diffuseIntensity: 0.02
            }
        },
        viewControl: {
            autoRotate: false
        }
    },
    series: []

};
{% endecharts %}

## Flights GL

{% echarts 400 '85%' %}
var uploadedDataURL = ROOT_PATH + "/data-gl/asset/data/flights.json";

myChart.showLoading();

$.getJSON(uploadedDataURL, function(data) {

    myChart.hideLoading();

    function getAirportCoord(idx) {
        return [data.airports[idx][3], data.airports[idx][4]];
    }
    var routes = data.routes.map(function (airline) {
        return [
            getAirportCoord(airline[1]),
            getAirportCoord(airline[2])
        ];
    });

    myChart.setOption({
        geo3D: {
            map: 'world',
            shading: 'realistic',
            silent: true,
            environment: '#333',
            realisticMaterial: {
                roughness: 0.8,
                metalness: 0
            },
            postEffect: {
                enable: true
            },
            groundPlane: {
                show: false
            },
            light: {
                main: {
                    intensity: 1,
                    alpha: 30
                },
                ambient: {
                    intensity: 0
                }
            },
            viewControl: {
                distance: 70,
                alpha: 89,

                panMouseButton: 'left',
                rotateMouseButton: 'right'
            },

            itemStyle: {
                areaColor: '#000'
            },

            regionHeight: 0.5
        },
        series: [{
            type: 'lines3D',

            coordinateSystem: 'geo3D',

            effect: {
                show: true,
                trailWidth: 1,
                trailOpacity: 0.5,
                trailLength: 0.2,
                constantSpeed: 5
            },

            blendMode: 'lighter',

            lineStyle: {
                width: 0.2,
                opacity: 0.05
            },

            data: routes
        }]
    });

    window.addEventListener('keydown', function () {
        myChart.dispatchAction({
            type: 'lines3DToggleEffect',
            seriesIndex: 0
        });
    });

});
{% endecharts %}
