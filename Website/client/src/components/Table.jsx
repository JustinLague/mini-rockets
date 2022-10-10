import { colors, Grid, Slider } from "@mui/material"
import React, { useEffect } from "react"
import { Api } from "../services/api.service"
import { Chart, Line } from "react-chartjs-2"
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

ChartJS.register(CategoryScale, LinearScale, PointElement, LineElement, Title, Tooltip, Filler, Legend)

const Table = ({ hoveredItem, setTimestamp, timestamp }) => {
    return (
        <React.Fragment>
            <section className='flex row-span-2'>
                <article className='grid gap-5 grid-cols-1 grid-rows-4 p-4 max-w-md align-top w-full border-double min-w-max mt-12 border-4 rounded-lg border-[#d8dee9]'>
                    <section className='flex flex-wrap'>
                        <h2 className=' font-bold text-lg basis-full'>Vitesse</h2>
                        <table className='grow text-left w-100'>
                            <thead>
                                <tr>
                                    <th>X</th>
                                    <th>Y</th>
                                    <th>Z</th>
                                </tr>
                            </thead>
                            <tbody>
                                <tr>
                                    <td>
                                        <code>{hoveredItem?.vX?.toFixed(2) ?? 0} m/s</code>
                                    </td>
                                    <td>
                                        <code>{hoveredItem?.vY?.toFixed(2) ?? 0} m/s</code>
                                    </td>
                                    <td>
                                        <code>{hoveredItem?.vZ?.toFixed(2) ?? 0} m/s</code>
                                    </td>
                                </tr>
                            </tbody>
                        </table>
                    </section>
                    <section className='flex flex-wrap'>
                        <h2 className=' font-bold text-lg basis-full'>Acceleration</h2>
                        <table className='grow text-left w-100'>
                            <thead>
                                <tr>
                                    <th>X</th>
                                    <th>Y</th>
                                    <th>Z</th>
                                </tr>
                            </thead>
                            <tbody>
                                <tr>
                                    <td>
                                        <code>
                                            {hoveredItem?.aX?.toFixed(2) ?? 0} m/s<sup>2</sup>
                                        </code>
                                    </td>
                                    <td>
                                        <code>
                                            {hoveredItem?.aY?.toFixed(2) ?? 0} m/s<sup>2</sup>
                                        </code>
                                    </td>
                                    <td>
                                        <code>
                                            {hoveredItem?.aZ?.toFixed(2) ?? 0} m/s<sup>2</sup>
                                        </code>
                                    </td>
                                </tr>
                            </tbody>
                        </table>
                    </section>
                    <section className='flex flex-wrap'>
                        <h2 className=' font-bold text-lg basis-full'>Angular Rate</h2>
                        <table className='grow text-left w-100'>
                            <thead>
                                <tr>
                                    <th>X</th>
                                    <th>Y</th>
                                    <th>Z</th>
                                </tr>
                            </thead>
                            <tbody>
                                <tr>
                                    <td>
                                        <code>
                                            {hoveredItem?.agX?.toFixed(2) ?? 0} m/s
                                            <sup>2</sup>
                                        </code>
                                    </td>
                                    <td>
                                        <code>
                                            {hoveredItem?.agY?.toFixed(2) ?? 0} m/s
                                            <sup>2</sup>
                                        </code>
                                    </td>
                                    <td>
                                        <code>
                                            {hoveredItem?.agZ?.toFixed(2) ?? 0} m/s
                                            <sup>2</sup>
                                        </code>
                                    </td>
                                </tr>
                            </tbody>
                        </table>
                    </section>
                    <section className='flex flex-wrap'>
                        <h2 className=' font-bold text-lg basis-full'>Other Measures</h2>
                        <table className='grow text-left w-100'>
                            <thead>
                                <tr>
                                    <th>Altitude</th>
                                    <th>Pressure</th>
                                    <th>Temperature</th>
                                </tr>
                            </thead>
                            <tbody>
                                <tr>
                                    <td>
                                        <code>{hoveredItem?.al?.toFixed(2) ?? 0} m</code>
                                    </td>
                                    <td>
                                        <code>{hoveredItem?.pr?.toFixed(2) ?? 0} PSI</code>
                                    </td>
                                    <td>
                                        <code>{hoveredItem?.te?.toFixed(2) ?? 0} &#176;C</code>
                                    </td>
                                </tr>
                            </tbody>
                        </table>
                    </section>
                    <section className='flex flex-wrap'>
                        <h1 className='text-xl basis-full'>Time = {hoveredItem?.timestamp ?? "N/A"} ms</h1>
                    </section>
                </article>
            </section>
        </React.Fragment>
    )
}

export default Table
