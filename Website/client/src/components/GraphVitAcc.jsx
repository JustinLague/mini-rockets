import React, { useEffect } from "react"
import { Api } from "../services/api.service"
import {
    Chart as ChartJS,
    CategoryScale,
    LinearScale,
    PointElement,
    LineElement,
    Title,
    Tooltip,
    Filler,
    Legend,
} from "chart.js"
import Table from "./Table"
import Graphs from "./Graphs"

ChartJS.register(CategoryScale, LinearScale, PointElement, LineElement, Title, Tooltip, Filler, Legend)

const GraphVitAcc = () => {
    const [dataset, setdataset] = React.useState([])
    const [data, setdata] = React.useState([])
    const [hoveredItem, setHoveredItem] = React.useState(0)
    const [isWarmup, setIsWarmup] = React.useState(false)

    useEffect(() => {
        const data = []
        for (let i = 0; i < 10000; i += 10) {
            data.push({
                id: i * 20,
                timestamp: i,
                al: (i / 1000 - 50) * (i / 1000 - 50),
                vX: Math.abs(((i - 100) * i) / 200000),
                vY: Math.abs(((i - 100) * i) / 100000),
                vZ: 0.04 * i - 100,
                aX: 0.01 * i - 100,
                aY: Math.abs(((i - 100) * i) / 1000000),
                aZ: 0.004 * i - 100,
                agX: 0,
                agY: Math.random() * 2 * Math.PI - Math.PI,
                agZ: 0,
                te: Math.abs(Math.random() * 2 * 10 - 10 + i),
                pr: Math.abs(Math.random() * 2 * 10 - 10 + i / 2),
            })
        }

        // change colours
        // Alt à part entre press et tableau

        const dataset = data.reduce(
            (p, c) => [
                {
                    ...p[0],
                    data: [...p[0].data, { x: c.timestamp, y: c.vX }],
                },
                {
                    ...p[1],
                    data: [...p[1].data, { x: c.timestamp, y: c.vY }],
                },
                {
                    ...p[2],
                    data: [...p[2].data, { x: c.timestamp, y: c.vZ }],
                },
                {
                    ...p[3],
                    data: [...p[3].data, { x: c.timestamp, y: c.aX }],
                },
                {
                    ...p[4],
                    data: [...p[4].data, { x: c.timestamp, y: c.aY }],
                },
                {
                    ...p[5],
                    data: [...p[5].data, { x: c.timestamp, y: c.aZ }],
                },
                {
                    ...p[6],
                    data: [...p[6].data, { x: c.timestamp, y: c.agX }],
                },
                {
                    ...p[7],
                    data: [...p[7].data, { x: c.timestamp, y: c.agY }],
                },
                {
                    ...p[8],
                    data: [...p[8].data, { x: c.timestamp, y: c.agZ }],
                },
                {
                    ...p[9],
                    data: [...p[9].data, { x: c.timestamp, y: c.al }],
                },
                {
                    ...p[10],
                    data: [...p[10].data, { x: c.timestamp, y: c.te }],
                },
                {
                    ...p[11],
                    data: [...p[11].data, { x: c.timestamp, y: c.pr }],
                },
            ],
            [
                {
                    fill: true,
                    borderWidth: 2,
                    pointBorderWidth: 1,
                    label: "Vitesse",
                    borderDash: [4, 1],
                    data: [],
                    backgroundColor: "#81a1c124",
                    borderColor: "#81a1c1AA",
                    pointRadius: 0,
                    pointBorderColor: "#81a1c1",
                    pointBackgroundColor: "#81a1c1",
                    pointHoveRadius: 2,
                },
                {
                    fill: true,
                    borderWidth: 2,
                    pointBorderWidth: 1,
                    label: "Vitesse",
                    borderDash: [4, 1],
                    data: [],
                    backgroundColor: "#81a1c124",
                    borderColor: "#81a1c1AA",
                    pointRadius: 0,
                    pointBorderColor: "#81a1c1",
                    pointBackgroundColor: "#81a1c1",
                    pointHoveRadius: 2,
                },
                {
                    fill: true,
                    borderWidth: 2,
                    pointBorderWidth: 1,
                    label: "Vitesse",
                    borderDash: [4, 1],
                    data: [],
                    backgroundColor: "#81a1c124",
                    borderColor: "#81a1c1AA",
                    pointRadius: 0,
                    pointBorderColor: "#81a1c1",
                    pointBackgroundColor: "#81a1c1",
                    pointHoveRadius: 2,
                },
                {
                    fill: false,
                    borderWidth: 2,
                    pointBorderWidth: 1,
                    label: "Acceleration",
                    borderDash: [8, 2],
                    data: [],
                    backgroundColor: "#bf616a00",
                    borderColor: "#bf616aAA",
                    pointRadius: 0,
                    pointBorderColor: "#bf616a",
                    pointBackgroundColor: "#bf616a",
                    pointHoveRadius: 2,
                },
                {
                    fill: false,
                    borderWidth: 2,
                    pointBorderWidth: 1,
                    label: "Acceleration",
                    borderDash: [8, 2],
                    data: [],
                    backgroundColor: "#bf616a00",
                    borderColor: "#bf616aAA",
                    pointRadius: 0,
                    pointBorderColor: "#bf616a",
                    pointBackgroundColor: "#bf616a",
                    pointHoveRadius: 2,
                },
                {
                    fill: false,
                    borderWidth: 2,
                    pointBorderWidth: 1,
                    label: "Acceleration",
                    borderDash: [8, 2],
                    data: [],
                    backgroundColor: "#bf616a00",
                    borderColor: "#bf616aAA",
                    pointRadius: 0,
                    pointBorderColor: "#bf616a",
                    pointBackgroundColor: "#bf616a",
                    pointHoveRadius: 2,
                },
                {
                    fill: false,
                    borderWidth: 2,
                    pointBorderWidth: 1,
                    label: "Angular Rate",
                    data: [],
                    backgroundColor: "#434c5e",
                    borderColor: "#434c5eAA",
                    pointRadius: 0,
                    pointBorderColor: "#434c5e",
                    pointBackgroundColor: "#434c5e",
                    pointHoveRadius: 2,
                },
                {
                    fill: false,
                    borderWidth: 2,
                    pointBorderWidth: 1,
                    label: "Angular Rate",
                    data: [],
                    backgroundColor: "#434c5e",
                    borderColor: "#434c5eAA",
                    pointRadius: 0,
                    pointBorderColor: "#434c5e",
                    pointBackgroundColor: "#434c5e",
                    pointHoveRadius: 2,
                },
                {
                    fill: false,
                    borderWidth: 2,
                    pointBorderWidth: 1,
                    label: "Angular Rate",
                    data: [],
                    backgroundColor: "#434c5e",
                    borderColor: "#434c5eAA",
                    pointRadius: 0,
                    pointBorderColor: "#434c5e",
                    pointBackgroundColor: "#434c5e",
                    pointHoveRadius: 2,
                },
                {
                    fill: false,
                    borderWidth: 3,
                    borderDash: [3, 3],
                    pointBorderWidth: 1,
                    label: "Altitude",
                    data: [],
                    backgroundColor: "#4c566a00",
                    borderColor: "#4c566a",
                    pointRadius: 0,
                    pointBorderColor: "#4c566a",
                    pointBackgroundColor: "#4c566a",
                    pointHoveRadius: 2,
                },
                {
                    fill: false,
                    borderWidth: 3,
                    pointBorderWidth: 1,
                    label: "Temperature",
                    data: [],
                    backgroundColor: "#8fbcbb",
                    borderColor: "#8fbcbb",
                    pointRadius: 0,
                    pointBorderColor: "#8fbcbb",
                    pointBackgroundColor: "#8fbcbb",
                    pointHoveRadius: 2,
                },
                {
                    fill: false,
                    borderWidth: 3,
                    pointBorderWidth: 1,
                    label: "Pression",
                    data: [],
                    backgroundColor: "#81a1c1",
                    borderColor: "#81a1c1",
                    pointRadius: 0,
                    pointBorderColor: "#81a1c1",
                    pointBackgroundColor: "#81a1c1",
                    pointHoveRadius: 2,
                },
            ]
        )
        setdataset(dataset)
        setdata(data)
        Api()
            .get("hello")
            .then((data) => {
                console.log(data)
            })
    }, [])

    return (
        <article className='grid grid-cols-3 grid-rows-3 container mx-auto'>
            <Table hoveredItem={hoveredItem} />
            <Graphs
                labels={data.map((d) => d.timestamp)}
                baseOptions={{
                    responsive: true,
                    interaction: {
                        mode: "nearest",
                        axis: "x",
                        intersect: false,
                    },
                    maintainAspectRatio: false,
                    stacked: false,
                    scales: {
                        y: {
                            type: "linear",
                            display: true,
                            position: "left",
                        },
                    },
                    plugins: {
                        title: {
                            display: true,
                            text: "Title",
                        },
                    },
                    onHover: (event, elements, chart) => {
                        if (elements.length > 0 && !isWarmup) {
                            setHoveredItem(data[elements[0].index])
                            setIsWarmup(true)
                        }
                        setTimeout(() => {
                            setIsWarmup(false)
                        }, 500)
                    },
                }}
                dataset={dataset}
            />
        </article>
    )
}

export default GraphVitAcc
